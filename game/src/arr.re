type arrFind('a) = 
  | True('a, int)
  | False;

let find = (arr: array('a), func): arrFind('a) => {
  let result = ref(False)
  Array.iteri((index, v) => {
    if (func(v)) {
      result := True(v, index);
    } else {
      result := False;
    }
  }, arr);
  result^;
}

let findO = (arr: array(option('a)), func): arrFind('a) => {
  let result = ref(False)
  Array.iteri((index, v) => {
    switch(v) {
      | Some(v) => {
        if (func(v)) {
          result := True(v, index);
        } else {
          result := False;
        }
      }
      | None => result := False;
    }
  }, arr);
  result^;
}