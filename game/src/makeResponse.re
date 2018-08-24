let getCodeInt = (code: DateType.code) => 
  switch (code) {
    | Error => 404
    | Success => 304
  }


let makeResponse = (result: DateType.res) => 
  switch (result) {
    | CreateGameSuccess(game) => [
      ("id", game.id |> string_of_int |> Json.parseOrRaise),
      ("actPlayer", game.actPlayer |> string_of_int |> Json.parseOrRaise),
    ] |> Json.Encode.object_
    | CreateGameFailed(code) => "error code" ++ (code |> getCodeInt |> string_of_int) |> Json.Encode.string
    | None => "doNotAct" |> Json.Encode.string
  }