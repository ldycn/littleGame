/* 最大的gameId，没有没回收的gameId之后使用maxGameId + 1作为Id */
let maxGameId = ref(-1);

/* 游戏完毕之后回收的gameId */
let overGamesId = ref([]);

/* 桌详细信息 */
let games: array(option(DateType.game)) = Array.make(10, None);

let setNewGameId = () => {
  switch (overGamesId^) {
    | [] => {
      maxGameId := maxGameId^ + 1;
      maxGameId^;
    }
    | [gameId, ...rest] => {
      overGamesId := rest;
      gameId;
    }
  }
};

let createGame = (id): DateType.game => {
  let gameId = setNewGameId();
  let newGame: DateType.game = {
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
  };
  games[gameId] = Some(newGame);
  newGame;
};

let endGame = (id) => {
  games[id] = None;
  overGamesId := [id, ...overGamesId^];
};

/* test */

/* createGame("123d");
createGame("123d");
createGame("123d");
createGame("123d");
Js.log(games); */

/* endGame(0);
endGame(1);
endGame(2);
endGame(3);
Js.log(games); */

/* createGame("123d");
createGame("123d");
endGame(0);
createGame("1asf");
Js.log(games); */

/* createGame("123d");
createGame("123d");
endGame(0);
createGame("1asf");
createGame("123d");
createGame("123d");
endGame(0);
endGame(1);
createGame("asfasf");
Js.log(games); */