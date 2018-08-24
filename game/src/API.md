## 射箭小游戏API v1
* 所有速度，位置大小为屏幕宽度比例
### 登录
* socket链接之后会收到该用户信息
* S-C
```
{
  id: string,
  name: string,
}
```
### 创建游戏
* C-S
```
{
  id: string,
  action: 'createGame',
}
```
* S-C
```
{
  action: 'create',
  action: 'shoot',
  gameId: string,
  actPlayer: string,
  players: [{
    id: string,
    position: [number, number],
    shootSpeed: number,
    rotateVec: number, // 每秒旋转的弧度
    rotataRange: [number, number] // 旋转角度范围，单位弧度
    boundingBox: [number, number], // x,y轴的偏移值 
  }],
}
```
### 射击
* C-S
```
{
  action: 'shoot',
  vec: number, // 弧度
  player: string,
  gameId: string,
}
```
* S-C
```
{
  action: 'shoot',
  result: 'headShot' | 'shot' | 'miss',
  nextPlayer: string,
  player: string,
  damage: number, // 满血为1
  gameId: string,
}
```
### end
{
  action: 'end',
  gameId: string,
  players: [{
    id: string,
    shoots: [{
      id: string,
      result: string,
      damage: number,
    }],
    state: 'win' | 'loss',
  }],
}

## 射箭小游戏API v0.1
* 所有速度，位置大小为屏幕宽度比例
### 登录
* socket链接之后会收到该用户信息
* S-C
```
{
  id: string,
  name: string,
}
```
### 创建游戏
* C-S
```
{
  action: 'create',
  id: string,
  action: 'createGame',
}
```
* S-C
```
{
  action: 'create',
  action: 'shoot',
  gameId: string,
  actPlayer: string,
  players: [{ // 长度为2,为玩家和射击物
    id: string,
    position: [number, number],
    shootSpeed: number,
    rotateVec: number, // 每秒旋转的弧度
    rotataRange: [number, number] // 旋转角度范围，单位弧度
    boundingBox: [number, number], // x,y轴的偏移值
  }],
}
```
### 射击
* C-S
```
{
  action: 'shoot',
  vec: number, // 弧度
  player: string,
  gameId: string,
}
```
* S-C
```
{
  action: 'shoot',
  result: 'shot' | 'miss',
  player: string,
  gameId: string,
}
```
### end
{
  action: 'end',
  gameId: string,
  players: [{
    id: string,
    state: 'win' | 'loss',
  }],
}
