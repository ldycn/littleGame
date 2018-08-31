type msgFromClient = {
  action: string,
  id: int,
}  

let getMsgFromClient = msg => Json.Decode.{
  action: msg |> Json.parseOrRaise |> field("action", string),
  id: msg |> Json.parseOrRaise |> field("id", string) |> int_of_string,
};

let decodeClientMsg = (msg): DateType.msg => {
  let contents = getMsgFromClient(msg);
  switch (contents.action) {
    | "createGame" => CreateGame(contents.id)
    | _ => None
  }
}

type clientConnect = {
  thirdPartId: string,
  ws: Ws.ws,
}

let decodeClientConnect = (msg): clientConnect => {
  let { thirdPartId } = getMsgFromClientConnect(msg);
  { thirdPartId, ws };
}