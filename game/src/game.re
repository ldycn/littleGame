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

/* createGame(315);
createGame(254);
createGame(151);
createGame(2235);
Js.log(games); */

/* endGame(0);
endGame(1);
endGame(2);
endGame(3);
Js.log(games); */

/* createGame(6346);
createGame(7454);
endGame(0);
createGame(568);
Js.log(games); */

/* createGame(679);
createGame(596);
endGame(0);
createGame(563);
createGame(53768);
createGame(484);
endGame(0);
endGame(1);
createGame(468);
Js.log(games); */