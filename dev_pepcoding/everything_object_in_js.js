var start = 1;
function lb() {
  console.log("-------------------- " + start + " ---------------------");
  start++;
}

let object = {
  name: "anand",
  roll: 40,
  fun: function (params) {
    console.log("this is the params that has been passed : " + params);
  },
};

console.log(object["ram"]); // see this key is not there in the object , so it will give undefined not error

console.log(object.length); // here the length will not be defined

object.fun("passing val");
// let us now print the object using for loop
for (var key in object) {
  console.log(object[key]);
}

lb();

// Now let us see the array is also an  object
var arr = [1, 3, 4, 5, "arr"];
for (var key in arr) {
  console.log(key); // look at this here , this printing proves that internally araray is
  // stored as object as well
}

console.log();
// now adding some key value pair and functions
arr.newkey = "this is new key";
arr.newfun = function () {
  console.log("this is function added in the array");
};

console.log(arr);

// see here we can access 60 th index, since it is like a key
console.log();
arr[68] = 3; // this is like {68:3}
console.log(arr[68], arr[60]);
// Note : the arary size will be 68 here
// ⭐⭐ so basically the objects  are emulated like arrays in js
lb();

// how shift works in const arrays

const arr2 = [1, 2, 3, 4, 5];
// How is it possible ??
arr2.shift();
console.log(arr2);
// because const saves the reference    


lb ( );
