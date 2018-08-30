const WebSocket = require('ws');
const { onConnection, onDisconnect, onMsg } = require('./socketFunc');
function doRespones(res) {
  res.forEach(({ targetWs, msg, act }) => {
    switch (act) {
      case 'emit':
        targetWs.emit(msg);
        break;
      case 'disConnect':
        targetWs.close();
        break;
      default:
        break;
    }
  });
}

function initSocket({ onConnection, onDisconnect, onMsg }) {
  const ws = new WebSocket.Server({ port: 1000 });
  ws.on('connection', (wsIns) => {
    // 发送成功登录消息
    const thirdPartId = 1;
    const res = onConnection(wsIns, thirdPartId);
    doRespones(res);
    // 注册该io回调
    wsIns.on('message', (msg) => {
      const res = onMsg(msg);
      doRespones(res);
    });
    wsIns.on('close', () => {
      const res = onDisconnect();
      doRespones(res);
    });
  });
}

initSocket({ onConnection, onDisconnect, onMsg });