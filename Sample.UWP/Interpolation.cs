using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Sample.UWP
{
	public static class Interpolation
	{
		#region Public Methods

		public static Vector2 GetPoint(Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3, float t, float alpha = 1)
		{
			if (p2 == p3)
			{
				p3 = Math2dF.LerpUnclamped(p1, p2, 2);
			}
			if (p0 == p1)
			{
				p0 = Math2dF.LerpUnclamped(p1, p2, -2);
			}

			const float k0 = 0;
			float k1 = GetKnotInterval(p0, p1, alpha);
			float k2 = GetKnotInterval(p1, p2, alpha) + k1;
			float k3 = GetKnotInterval(p2, p3, alpha) + k2;

			// evaluate the point
			float u = Math2dF.LerpUnclamped(k1, k2, t);
			Vector2 A1 = Remap(k0, k1, p0, p1, u);
			Vector2 A2 = Remap(k1, k2, p1, p2, u);
			Vector2 A3 = Remap(k2, k3, p2, p3, u);
			Vector2 B1 = Remap(k0, k2, A1, A2, u);
			Vector2 B2 = Remap(k1, k3, A2, A3, u);
			return Remap(k1, k2, B1, B2, u);
		}

		static Vector2 Remap(float a, float b, Vector2 c, Vector2 d, float u)
		{
			return Math2dF.LerpUnclamped(c, d, (u - a) / (b - a));
		}

		static float GetKnotInterval(Vector2 a, Vector2 b, float alpha)
		{
			return Math2dF.Pow(Math2dF.SqrMagnitude(a - b), 0.5f * alpha);
		}
		#endregion Public Methods
	}
	public static class Math2dF
	{
		public static float LerpUnclamped(float a, float b, float t)
		{
			return a + (b - a) * t;
		}

		public static Vector2 LerpUnclamped(Vector2 a, Vector2 b, float t)
		{
			var res = a + (b - a) * t;

			if (float.IsNaN(res.X))
			{

			}

			return res;
		}

		public static float SqrMagnitude(Vector2 vector)
		{
			return vector.X * vector.X + vector.Y * vector.Y;
		}

		public static float Pow(float target, float amount)
		{
			return (float)Math.Pow(target, amount);
		}
	}
	public class InterpolationData
	{
		public List<WeightVector2> FullInterpolated { get; set; } = new List<WeightVector2>();

		public List<WeightVector2> SemiInterpolated { get; set; } = new List<WeightVector2>();
	}

	public struct WeightVector2
	{
		public Vector2 Value { get; set; }

		public float Distance { get; set; }

		public float Size { get; set; }

		public static implicit operator Vector2(WeightVector2 w) => w.Value;

		public static bool operator ==(WeightVector2 left, WeightVector2 right) => left.Value == right.Value;
		public static bool operator !=(WeightVector2 left, WeightVector2 right) => left.Value != right.Value;

		public static WeightVector2 operator -(WeightVector2 left, WeightVector2 right) => new WeightVector2()
		{
			Value = left.Value - right.Value
		};

		public float Length()
		{
			return Value.Length();
		}

	}

	public sealed class LineBuilder
	{

		private List<WeightVector2> _rawPoints = new List<WeightVector2>();

		private List<WeightVector2> _fullInterpolatedPoints = new List<WeightVector2>();

		private WeightVector2 _lastFoundedPoint;


		public float Distance { get; set; }

		private float _currentDistance;

		public WeightVector2 StartBuilding(WeightVector2 point)
		{
			_rawPoints.Add(point);
			_lastFoundedPoint = point;
			return point;
		}

		public InterpolationData AddPoint(WeightVector2 point)
		{
			_rawPoints.Add(point);

			Debug.WriteLine($"Point distance - {(point.Value - _rawPoints[_rawPoints.Count - 2]).Length()}");

			(var fullInterpolated, var dis, var pnt) = _rawPoints.Count > 2 ? Interpolate(_rawPoints.Count - 3, _rawPoints, _currentDistance, _lastFoundedPoint) : (new List<WeightVector2>(), 0, new WeightVector2());

			if (_rawPoints.Count > 2)
			{
				_lastFoundedPoint = pnt;
			}

			_currentDistance = dis;

			Debug.WriteLine(_currentDistance);


			var data = Interpolate(_rawPoints.Count - 2, _rawPoints, _currentDistance, _lastFoundedPoint);


			return new InterpolationData()
			{
				SemiInterpolated = data.Item1,
				FullInterpolated = fullInterpolated
			};
		}


		private (List<WeightVector2>, float, WeightVector2) Interpolate(int startIndex, List<WeightVector2> points, float currentDistance, WeightVector2 lastFoundedPoint)
		{
			WeightVector2 firstWeightPoint = startIndex == 0 ? points[startIndex] - points[startIndex + 1] : points[startIndex - 1];
			WeightVector2 startPoint = points[startIndex];
			WeightVector2 endPoint = points[startIndex + 1];
			WeightVector2 secondWeightPoint = startIndex < points.Count - 2 ? points[startIndex + 2] : points[startIndex + 1] - points[startIndex];

			if (startPoint == endPoint)
			{
				return (new List<WeightVector2>(), currentDistance, lastFoundedPoint);
			}

			List<WeightVector2> newPoints = new List<WeightVector2>();

			int pointsCount = (int)MathF.Max(3, (int)(endPoint - startPoint).Length());

			List<WeightVector2> interpolatedPoint = new List<WeightVector2>();

			float totalSplineLenght = 0;

			for (int i = 0; i < pointsCount; i++)
			{
				var newPoint = Interpolation.GetPoint(firstWeightPoint, startPoint, endPoint, secondWeightPoint, i / (float)pointsCount);
				interpolatedPoint.Add(new WeightVector2()
				{
					Value = newPoint
				});

				if (i == 0)
				{
					totalSplineLenght += (startPoint - newPoint).Length();
				}
				else
				{
					totalSplineLenght += (newPoint - interpolatedPoint[i - 1]).Length();
				}
			}
			float currentSplineLength = 0;

			for (int i = 0; i < pointsCount; i++)
			{
				var newPoint = interpolatedPoint[i];
				var pointsLength = (newPoint - lastFoundedPoint).Length();

				if (i > 0)
				{
					currentSplineLength += (interpolatedPoint[i] - interpolatedPoint[i - 1]).Length();
				}

				float distance = Math.Max(1, (points[startIndex + 1].Distance + points[startIndex].Distance) / 2);

				if (pointsLength + currentDistance >= distance)
				{
					var dis = pointsLength + currentDistance;
					var drawPoint = Math2dF.LerpUnclamped(lastFoundedPoint, newPoint, (distance - currentDistance) / pointsLength);



					newPoints.Add(new WeightVector2()
					{
						Value = drawPoint,
						Size = Math2dF.LerpUnclamped(startPoint.Size, endPoint.Size, (currentSplineLength + (newPoint - drawPoint).Length()) / totalSplineLenght)
					});
					lastFoundedPoint = new WeightVector2()
					{
						Value = drawPoint,
						Size = Math2dF.LerpUnclamped(startPoint.Size, endPoint.Size, (currentSplineLength + (newPoint - drawPoint).Length()) / totalSplineLenght)
					};
					currentDistance = 0;

					float targetDistance = distance;

					if (targetDistance > 0)
					{
						while ((newPoint - lastFoundedPoint).Length() >= targetDistance)
						{
							dis = (newPoint - lastFoundedPoint).Length() + currentDistance;
							drawPoint = Math2dF.LerpUnclamped(lastFoundedPoint, newPoint, (distance - currentDistance) / (newPoint - lastFoundedPoint).Length());
							newPoints.Add(new WeightVector2()
							{
								Value = drawPoint,
								Size = Math2dF.LerpUnclamped(startPoint.Size, endPoint.Size, (currentSplineLength + (newPoint - drawPoint).Length()) / totalSplineLenght)
							});


							lastFoundedPoint = new WeightVector2()
							{
								Value = drawPoint
							};

							currentDistance = 0;
						}
					}

				}
				else
				{
					currentDistance += pointsLength;
					lastFoundedPoint = newPoint;

				}



			}

			return (newPoints, currentDistance, lastFoundedPoint);
		}

		public void FinishBuilding()
		{
			_rawPoints = new List<WeightVector2>();
			_fullInterpolatedPoints = new List<WeightVector2>();
			_currentDistance = 0;
		}
	}
}
