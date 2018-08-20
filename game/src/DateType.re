Js.log("Hello, BuckleScript and Reason!");

type playerInit = {
  id: string,
  position: (float, float),
  shootSpeed: float,
  rotateVec: float,
  rotataRange: (float, float),
  boundingBox: (float, float),
};

type game = {
  id: string,
  players: playerInit,
  lactPlayer: string,
};

type user = {
  id: string,
  name: string,
};