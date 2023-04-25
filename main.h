class Point
{
public:
	float x = 0.f;
	float y = 0.f;
	float z = 0.f;

	Point();
	Point(float x, float y, float z);

	void operator+=(Point vec);
	void operator/=(float s);
	void operator-=(Point vec);
	void operator*=(float Array[][]);

	Point operator+(Point vec);

private:

};

class Pyramid
{
public:
	int verticesLength = 8;
	int edgesLength = 12;

	Point center = Point(250, 250, 0);
	Point rotateVec = Point(0, 0, 0);

	Point vertices[8] = {
	Point(0, 0, 0),
	Point(1.f, 0, 0),
	Point(0.5, pow(3, 1 / 2) / 2, 0),
	Point(0.5, pow(3, 1 / 2) / 6, pow(6, 1 / 2) / 3), };

	int edges[12][2] = {
	{0, 1},
	{1, 2},
	{2, 0},
	{0, 3},
	{1, 3},
	{2, 3}, };

	Pyramid();

	void drawLine(Point point1, Point point2);
	void move(Point delta);
	void rotate(Point rotateVector);
	Point findCenter();
	void scale(float ratio);
	void render();

private:

};

void multiply(float a[4][4], Point *point);
void print();