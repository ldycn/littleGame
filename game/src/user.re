let maxId = ref(-1);

let getId = () => {
  maxId := maxId^ + 1;
  maxId;
}
let user: array(option(DateType.user)) = Array.make(10, None);


let isExsistUser = (thirdPartId): option(DateType.user) => {
  let result = Arr.findO(user, (user) => {
    switch (user) {
      | Some(user) => {
        if (user.thirdPartId === thirdPartId) {
          true;
        } else {
          false;
        }
      }
      | None => false
    }
  });
}

let login = (thirdPartId, ws): DateType.user => {
  switch (isExsistUser(thirdPartId)) {
    | Some(user) => user
    | None => {
      let id = getId();
      let newUser = {
        id,
        thirdPartId,
        name: "游客" ++ string_of_int(id),
      };
      user[id] = newUser;
      newUser;
    }
  }
}