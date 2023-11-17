var start = 1;
function lb() {
  console.log("-------------------- " + start + " ---------------------");
  start++;
}

// 1 ) assigning and reassining and re initilisation
console.log(a);

var a = 10;
console.log(a);

a = 20;
console.log(a);
var a; // here a has been declared again but not intiliased so to avoid
// undefined printing it will print the previous one
// but if we had initiliased then it will print that only

console.log(a);

lb();

// 2 ) var are function scoped ⭐⭐, so once it is changed inside the function , ever changed after declaring still it will be  same  , overwritten , since
// one function has only one execution stack , so it will not be overwritten, or two values for the same variable is maintained

function fn() {
  console.log(a);
  var a = 10;
  console.log(a);
  if (a == 10) {
    var a = 20; // see at this moment var will be overwritten its not like
    // the last 10 will be kept seperate , a will be overwritten with 20 forever
    // so redefing same variable with initialisation is same as reassigning ⭐⭐⭐
    console.log(a);
  }
  console.log(a);
}
fn();

lb();

// 3 ) question  mixture of 1 and 2 ⭐⭐⭐

var a = 10;
console.log("line number 2", a);
function fn() {
  console.log("line number 4", a);
  var a = 20;
  a++;
  console.log("line number 7", a);
  if (a) {
    var a = 30; // here this declaration and initilisation comes under the scope of a , so it will be overwritten
    a++;
    console.log("line number 11", a);
  }
  console.log("line number 13", a);
}
fn();
console.log("line number 2", a); // see this will not change, since fn has different

lb();
// execution scope it will not effect other scope a

// 4 ) question on let , and how it is different from var ⭐⭐⭐

let letFruit = "orange";
var varFruit = "orange";
console.log(" left Fruit : ", letFruit, "varFruit : ", varFruit);
{
  let letFruit = "apple";
  var varFruit = " apple";
  console.log(" left Fruit : ", letFruit, "varFruit : ", varFruit);
}
console.log(" left Fruit : ", letFruit, "varFruit : ", varFruit);

