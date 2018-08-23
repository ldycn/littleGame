let getYMove = (time, initSpeed, gravity) => {
  initSpeed *. time -. (0.5 *. gravity *. time *. time)
}

let pai = 3.1415;

let getRad = (arc) => 2.0 *. pai /. (360.0 /. arc);
/* 点状物射击方形物体，仅受重力 */
let getShootResult = (mePos, targetPosBox, shootSpeed, shootArc, gravity): DateType.shoot => {
  let rad = getRad(shootArc);
  let (speedX, speedY) = (sin(rad) *. shootSpeed, cos(rad) *. shootSpeed);
  Js.log((speedX, speedY));
  let ((targetX1, targetX2), (targetYLow, targetYHigh)) = targetPosBox;
  let (mePosX, mePosY) = mePos
  let (timeRange1, timeRange2) = ((targetX1 -. mePosX) /. speedX, (targetX2 -. mePosX) /. speedX);
  Js.log((timeRange1, timeRange2));
  let (yRangeHigh, yRangeLow) = (mePosY +. getYMove(timeRange1, speedY, gravity), mePosY +. getYMove(timeRange2, speedY, gravity));
  Js.log((yRangeHigh, yRangeLow));
  if (yRangeHigh < targetYLow || yRangeLow > targetYHigh) {
    Miss
  } else {
    Shot
  }
}

let test = getShootResult((0.1, 0.1), ((0.8, 0.9), (0.1, 0.2)), 0.3, 45.0 , 0.2);

Js.log(test);
 
/* let getShootOrbit = (time) => (initPos, speed, speedRed, acc accRed) => {
  let (speedX, speedY) = (cos(speedRed) *. speed, sin(speedRed) *. speed);
  let (accX, accY) = (cos(accRed) *. acc, sin(accRed) *. acc);
} */
