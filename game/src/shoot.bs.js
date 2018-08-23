// Generated by BUCKLESCRIPT VERSION 3.0.0, PLEASE EDIT WITH CARE
'use strict';


function getYMove(time, initSpeed, gravity) {
  return initSpeed * time - 0.5 * gravity * time * time;
}

function getRad(arc) {
  return 2.0 * 3.1415 / (360.0 / arc);
}

function getShootResult(mePos, targetPosBox, shootSpeed, shootArc, gravity) {
  var rad = getRad(shootArc);
  var speedX = Math.sin(rad) * shootSpeed;
  var speedY = Math.cos(rad) * shootSpeed;
  console.log(/* tuple */[
        speedX,
        speedY
      ]);
  var mePosY = mePos[1];
  var mePosX = mePos[0];
  var match = targetPosBox[1];
  var match$1 = targetPosBox[0];
  var timeRange1 = (match$1[0] - mePosX) / speedX;
  var timeRange2 = (match$1[1] - mePosX) / speedX;
  console.log(/* tuple */[
        timeRange1,
        timeRange2
      ]);
  var yRangeHigh = mePosY + getYMove(timeRange1, speedY, gravity);
  var yRangeLow = mePosY + getYMove(timeRange2, speedY, gravity);
  console.log(/* tuple */[
        yRangeHigh,
        yRangeLow
      ]);
  if (yRangeHigh < match[0] || yRangeLow > match[1]) {
    return /* Miss */0;
  } else {
    return /* Shot */1;
  }
}

var test = getShootResult(/* tuple */[
      0.1,
      0.1
    ], /* tuple */[
      /* tuple */[
        0.8,
        0.9
      ],
      /* tuple */[
        0.1,
        0.2
      ]
    ], 0.3, 45.0, 0.2);

console.log(test);

var pai = 3.1415;

exports.getYMove = getYMove;
exports.pai = pai;
exports.getRad = getRad;
exports.getShootResult = getShootResult;
exports.test = test;
/* test Not a pure module */
