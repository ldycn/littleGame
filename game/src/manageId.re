let initIdManagement = () => {
  /* 最大的id，没有没回收的id之后使用maxId + 1作为id */
  let maxId = ref(-1);

  /* 游戏完毕之后回收的gameId */
  let tempId = ref([]);

  let recycleId = (id: int) => tempId := [id, ...tempId^];

  let getId = () => {
    switch (tempId^) {
      | [] => {
        maxId := maxId^ + 1;
        maxId^;
      }
      | [id, ...rest] => {
        tempId := rest;
        id;
      }
    }
  };
  (getId, recycleId);
}