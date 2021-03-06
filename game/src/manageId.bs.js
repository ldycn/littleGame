// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';


function initIdManagement() {
  var maxId = /* record */[/* contents */-1];
  var tempId = /* record */[/* contents : [] */0];
  var recycleId = function (id) {
    tempId[0] = /* :: */[
      id,
      tempId[0]
    ];
    return /* () */0;
  };
  var getId = function () {
    var match = tempId[0];
    if (match) {
      tempId[0] = match[1];
      return match[0];
    } else {
      maxId[0] = maxId[0] + 1 | 0;
      return maxId[0];
    }
  };
  return /* tuple */[
          getId,
          recycleId
        ];
}

exports.initIdManagement = initIdManagement;
/* No side effect */
