let msg = {js| { "action": "createDesk", "id": "1" } |js};

msg
  |> DecodeMsg.decodeClientMsg
  |> DoMsg.doMsg
  |> MakeResponse.makeResponse
  |> Js.Json.stringify
  |> Js.log;