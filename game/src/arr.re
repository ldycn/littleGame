type arrFind('a) = 
  | Ture('a', int)
  | False;

let find = (arr: array('a), func): arrFind('a) => {
  let result = ref(False)
  Array.iteri((index, v) => {
    if (func(v)) {
      result := Ture(v, index);
    } else {
      result := False;
    }
  });
  result;
}