let maxId = ref(-1);

let getId = () => {
  maxId := maxId^ + 1;
  maxId
}
let user: array(option(DateType.user)) = Array.make(10, None);

let find = (func, arr: array('a)): DateType.arrFind('a) => {
  open DateType;
  let a = ref(False);
  Array.map((v) => {
    if (func(v)) {
      a := Ture(v);
    } else {
      a := False
    };
  });
  a^;
}

/* let isExsistUser = () => {
  Array.map
} */
/* let login = (thirdPartId): DateType.user => {
  if (isExsistUser(thirdPartId)) {

  } else {
    let id = getId();
    {
      id,
      thirdPartId,
      name: "游客" ++ string_of_int(id),
    }
  }
} */