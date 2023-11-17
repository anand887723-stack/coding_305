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

// 2 ) var are function scoped ⭐⭐, so once it is changed inside the function ,  it will be changed for that execution stack as a whole
// since one function has only one execution stack , so no two values for the same variable is maintained

// redefining the variable is also similar to this , redefining the variable will not imply
// that the 2 different seperate values are maintained for the same variable.

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
// execution scope it will not effect other scope of a

lb();

//LET AND CONST
// 4 )  let redeclare ❌ , intilisation ( not must ), reassign  ✅

// let varName;
// console.log("varName on line number 5", varName);
// varName = 10;
// varName = 20;
// console.log("varName on line number 8", varName);
// let varName; // this is error in code  , this will not run , not one line above will run

lb();

// 5) const reassign ❌ redeclare ❌ initilisation ( must )
const constant = 10;

lb();

//  6) Temporal  dead zone for var
// note this is not error, this is a safety measure that must be resolved to procced further , before lines , implemented ✅ , after lines ❌

// Cannot access 'varName' before initialization
// console.log("Hello"); //hello will run
// console.log("varName on line number 5", varName2);

// // declare
// let varName2;
// // default-> undefined
// console.log("varName on line number 5", varName2);
// varName2 = 10;
// varName2 = 20;
// console.log("varName on line number 8", varName2);

// lb();

// 7 ) blocks  : {} - one block
// special relation with let  and const -- their memory is allocated each time the  block is made.

let fruits = "apple";

console.log(fruits);

{
  // the thing is fruits can see that in my scope later fruits it has been defined
  // so it will not take the outside scope value , so actually once it sees that value has been
  // defined in my scope it will go into tdz if it accessed before.
  // console.log(fruits); //--TDZ
  let fruits;
  console.log(fruits);
  fruits = "orange";
  console.log(fruits); // this will take the its most nearest block value
}
console.log(fruits); // this will print the apple  , since that is out side the block

lb();

let fruits2 = "apple";
console.log(fruits);
{
  let fruits2;
  console.log(fruits2);
  fruits2 = "orange";
  {
    console.log(fruits2); // this will take the its most nearest block value , will ont give error , if something is defined anywhere in the above blocks
  }
  console.log(fruits2); // this will take the its most nearest block value
}
console.log(fruits2); // this will print the apple  , since that is out side the block

lb();

// 8 ) variable shadowing
// let , let will give apple orange appple
// var, var will give apple orange orange , since var is function scoped
// let , var not allowed since the var is scoped outside so this will imply that let is redecleared
// var , let will be apple, orange , apple , since the let is {} scoped 

var f3 = "apple";
console.log(fruits);
{
  let f3 = "orange"; // for this scope , value of fruits3 will be this orange
  console.log(f3); // this will take the its most nearest block value
}
console.log(f3); // this will print the apple  , since that is out side the block

lb();

// note  1: in the inner scope we can define the fruit with let or const, there will no issue, it will be shadowed
// note 2 : outside let and cost and inside  var is illegal since var has funtional scope

// 9 ) question ⭐⭐⭐

let letFruit = "orange";
var varFruit = "orange";
console.log("leftFruit", letFruit, "varFruit", varFruit);
{
  let letFruit = "apple"; // let  is scoped thing
  var varFruit = "apple"; // var has the funtion scope
  console.log("leftFruit", letFruit, "varFruit", varFruit);
}
console.log("leftFruit", letFruit, "varFruit", varFruit);
// feel let is just bracket scoped but var is global