type playerInit = {
  id: int,
  position: (float, float),
  shootSpeed: float,
  rotateVec: float,
  rotataRange: (float, float),
  boundingBox: (float, float),
};

type game = {
  id: int,
  players: array(playerInit),
  actPlayer: int,
};

type onlineState = 
  | OnLine
  | UnKnown
  | OffLine

type user = {
  id: int,
  name: string,
  thirdPartId: string,
  onLineState, 
};

type code = 
  | Error
  | Success;

type errorCode =
  | Unknown
type shoot = 
  | Miss
  | Shot
  | HeadShot;

type funcState = 
  | Success
  | Failed;
  
type msg =
  | CreateGame(int)
  | None;

type res =
  | CreateGameSuccess(game)
  | CreateGameFailed(code)
  | None;