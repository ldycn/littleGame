type msgFromClient = {
  action: string,
  id: int,
}  

let getMsgContents = msg => Json.Decode.{
  action: msg |> Json.parseOrRaise |> field("action", string),
  id: msg |> Json.parseOrRaise |> field("id", string) |> int_of_string,
};

let decodeMsg = (msg): DateType.msg => {
  Js.log(1)
  let contents = getMsgContents(msg);
  Js.log(1)
  switch (contents.action) {
    | "createGame" => CreateGame(contents.id)
    | _ => None
  }
}