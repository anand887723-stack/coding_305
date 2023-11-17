// ✅  :revision

var start = 1;
function lb() {
  console.log("-------------------- " + start + " ---------------------");
  start++;
}

// 1 . printing this and global
// fxn inside ❌ -> global area

console.log(global);
console.log(this);
lb();
// 2. observing when things are located with memory during exectution .

console.log("a is", a); //-- see here undefined is given already
var a;
console.log("a is", a);
a = 10;
console.log("a is", a);

lb();

//  3.observing how function memory allocation works  function statements

fn(); // -- so the basic thing is memory is  allocated at the start itself
function fn() {
  console.log("I can be called before my declaration");
}

lb();

// 4 question for the illustration of 3 ⭐⭐⭐⭐⭐⭐

real();
function real() {
  console.log("I am real. Always run me");
}

real();
function real() {
  console.log("😲 No I am real one ");
}

real();
function real() {
  console.log("You both are wasted 😂😂");   // function memory is allocated for the final function then program is allowed to run 
}

real();

lb();


// 5 , qeustion based on 2 and 3  ⭐⭐⭐⭐

console.log("varName", varName);
var varName;
console.log("varName", varName);
varName = "Captain America";
console.log("varName", varName);
fn();
function fn() {
  console.log("Hello from fn");
}
fn();
// fnContainer();  //-- this will give the error ( proper error )
var fnContainer = function () {
  console.log(" I am an Expression");
};
fnContainer();


lb();

// 6. We know code runs under execution context  , which is under stack known as call stack
// scopes of variables

var a = 2;
console.log(a);
function fun1() {
  console.log(a); // here it will give undefined . because it will see
  // that in the function after this statement a is defined so it will wait for that
  // and will give undefined till now

  var a = 3;

  console.log(a);

  function fun2() {
    console.log(a); // it will pick the nearest scope out of the function definition
  }
  fun2();
}

function fun3() {
  console.log(a); // here it will not give undefined
}

fun1();
fun3();
lb();

// 7. now let us see from where the scope is calculated from( lexical scope)⭐⭐⭐⭐

var a = 2;

function f1() {
  console.log(a);
}

function f2() {
  var a = 3;
  f1();

  function f4() {
    console.log(a);
  }
  f4(); // but this will print 3 
}

f2(); // see it will print 2 but on the same time




