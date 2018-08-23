/* 最大的gameId，没有没回收的gameId之后使用maxGameId + 1作为Id */
let maxGameId = ref("-1")

/* 游戏完毕之后回收的gameId */
let overGamesId = ref([])

/* 桌详细信息 */
let games: array(option(DateType.game)) = Array.make(1000, None)

let createGame = (id): DateType.game => {
  switch (overGamesId^) {
    | [] => {
      maxGameId := string_of_int(int_of_string(maxGameId^) + 1);
      {
        id: maxGameId^,
        actPlayer: id,
        players: [|{
          id,
          position: (0.1, 0.1),
          shootSpeed: 0.3,
          rotateVec: 0.3,
          rotataRange: (0.0, 0.75),
          boundingBox: (0.05, 0.05),
        }|],
      }
    }
    | [gameId, ...rest] => {
      overGamesId := rest;
      {
        id: gameId,
        actPlayer: id,
        players: [|{
          id,
          position: (0.1, 0.1),
          shootSpeed: 0.3,
          rotateVec: 0.3,
          rotataRange: (0.0, 0.75),
          boundingBox: (0.05, 0.05),
        }|],
      }
    }
  }
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
