type playerInit = {
  id: string,
  position: (float, float),
  shootSpeed: float,
  rotateVec: float,
  rotataRange: (float, float),
  boundingBox: (float, float),
}

type game = {
  id: string,
  players: array(playerInit),
  actPlayer: string,
}

type user = {
  id: string,
  name: string,
}

type shoot = 
  | Miss
  | shot

type funcState = 
  | Success
  | Failed