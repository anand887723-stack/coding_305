var start = 1;
function lb() {
  console.log("-------------------- " + start + " ---------------------");
  start++;
}

// function is an object but here we need to access the keys as fn.()

function fn() {
  console.log(" this is main function");
}

fn.prop = "this is a key val pair";
fn.newfunc = function () {
  console.log("this is new method in the main function");
};

//see here in the fn object itself we are defining another function
// and also we are defining another key value pair

fn();

// this gives error although
// for (var key in fn) {
//   print(key);
// }

fn.newfunc();

console.log(fn.prop); // not here we cannot call prop as fn[prop]
lb ( );


// ⭐⭐⭐ so what are primitive types if everything is object in js
// number, string, boolean, undefined, null, symbol