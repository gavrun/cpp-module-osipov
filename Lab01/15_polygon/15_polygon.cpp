#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>


// Single point structure
struct Vertex {
	long double xCoord{};
	long double yCoord{};
};

// Shoelace area for a simple polygon
long double polygon_area_shoelace(const std::vector<Vertex>& vertices) {
	const size_t vertexCount = vertices.size();
	long double sumCrossProducts = 0.0L;

	for (size_t i = 0; i < vertexCount; ++i) {
		const Vertex& currentVtx = vertices[i];
		const Vertex& nextVtx = vertices[(i + 1) % vertexCount]; // wrap-around

		sumCrossProducts += currentVtx.xCoord * nextVtx.yCoord - nextVtx.xCoord * currentVtx.yCoord;
	}

	return std::fabsl(sumCrossProducts) * 0.5L;
}


int main()
{
	std::cout << "Enter coordinates for 5 vertices (x y) of polygon in traversal order:\n";

	std::vector<Vertex> polygonVertices(5);

	for (int i = 0; i < 5; ++i) {
		// Read coordinates; input format: x y
		if (!(std::cin >> polygonVertices[i].xCoord >> polygonVertices[i].yCoord)) {
			std::cerr << "Input error at vertex " << (i + 1) << "\n";
			return 1;
		}
	}

	long double sPolyArea = polygon_area_shoelace(polygonVertices);

	std::cout << std::fixed << std::setprecision(2);

	std::cout << "Polygon area = " << static_cast<double>(sPolyArea) << "\n";

	return 0;
}

