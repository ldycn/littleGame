let doMsg = (msg: DateType.msg): DateType.res =>
  switch (msg) {
    /* | CreateGame(userId) => CreateGameSuccess(Game.createGame(userId)) */
    | CreateGame(userId) => CreateGameFailed(Error)
    | None => None
  }