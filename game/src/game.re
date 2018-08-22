let gameId = "0"
/* [|None|] */
let games: array(option(DateType.game)) = Array.make(1000, None)
let createGame = (id): DateType.game => {
  id: "0",
  actPlayer: id,
  players: [|{
    id,
    position: (0.1, 0.1),
    shootSpeed: 0.3,
    rotateVec: 0.3,
    rotataRange: (0.0, 0.75),
    boundingBox: (0.05, 0.05),
  }, {
    id: "100001",
    position: (0.1, 0.1),
    shootSpeed: 0.3,
    rotateVec: 0.3,
    rotataRange: (0.0, 0.75),
    boundingBox: (0.05, 0.05),
  }|],
}
let initArrNone = id => (game): option(DateType.game) => {
  switch (game) {
    | Some(data: DateType.game) => {
      if (data.id === id) {
        None
      } else {
        Some(data)
      }
    }
    | None => None
  }
}
let endGame = (id): bool => {
  Array.map(initArrNone(id), games) |> ignore;
  true;
}
