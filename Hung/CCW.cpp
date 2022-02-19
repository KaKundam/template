bool cw (pt a, pt b, pt c) { // a -> b -> c đi theo thứ tự xuôi chiều kim đồng hồ
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) { // a -> b -> c đi theo thứ tự ngược chiều kim đồng hồ
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}