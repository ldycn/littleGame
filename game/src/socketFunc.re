/* 不是string类型，外部对象，re只负责传递 */
type ws = string;

type res = list({
  targetWs: ws,
  msg: Js.Json.t,
  act: string,
});

let onConnection: ({ ws: ws, thirdPartId: Js.Json.t }): res => {
  User.login({ ws: ws, thirdPartId: Js.Json.t })
}