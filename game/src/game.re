let gameId = "0";

type game = option(DateType.game)
let games: [game] = [|{}|]
let createGame = (id): DateType.game => {
  id: gameId,
  actPlayer: string,
  players: [{
    id,
    position: (0.1, 0.1),
    shootSpeed: 0.3,
    rotateVec: 0.3,
    rotataRange: (0, 0.75),
    boundingBox: (0.05, 0.05),
  }, {
    id: "100001",
    position: (0.1, 0.1),
    shootSpeed: 0.3,
    rotateVec: 0.3,
    rotataRange: (0, 0.75),
    boundingBox: (0.05, 0.05),
  }],
}
let endGame = (id): DateType.FuncState => {
  games[0] = {};
  Success;
}