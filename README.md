Ray casting algorithm
One simple way of finding whether the point is inside or outside a simple polygon is to test how many times a ray, 
starting from the point and going in any fixed direction, intersects the edges of the polygon.
If the point is on the outside of the polygon the ray will intersect its edge an even number of times. 
If the point is on the inside of the polygon then it will intersect the edge an odd number of times. 
Unfortunately, this method won't work if the point is on the edge of the polygon.
