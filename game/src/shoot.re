let getYMove = (time, initSpeed, gravity) => {
  initSpeed ** time -. (0.5 ** gravity ** time ** time)
}

let getShootResult = (mePos, targetPosBox, shootSpeed, shootRad, gravity): DateType.shoot => {
  let (speedX, speedY) = (sin(shootRad) ** shootSpeed, cos(shootRad) ** shootSpeed);
  let ((targetX1, targetX2), (targetYLow, targetYHigh)) = targetPosBox;
  let (mePosX, mePosY) = mePos;
  let (timeRange1, timeRange2) = ((targetX1 -. mePosX) /. speedX, (targetX2 -. mePosX) /. speedX);
  let (yRangeHigh, yRangeLow) = (getYMove(timeRange1, speedY, gravity), getYMove(timeRange2, speedY, gravity))
  if ( yRangeHigh < targetYLow || yRangeLow > targetYHigh) {
    MISS
  } else {
    SHOOT
  }
}