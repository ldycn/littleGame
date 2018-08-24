let msg = {js| { "action": "createDesk", "id": "1" } |js};

msg
  |> DecodeMsg.decodeMsg
  |> DoMsg.doMsg
  |> MakeResponse.makeResponse
  |> Js.Json.stringify
  |> Js.log;