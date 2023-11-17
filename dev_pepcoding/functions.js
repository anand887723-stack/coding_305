// ✅ : revision

let start = 1;
function linebreak() {
  console.log(
    "-------------------------- " + start + " ------------------------------"
  );
  start++;
}

// functions

// 1.  undefined  is returned when we are not returning anything    and if we are not passing anything
//     when it is needed to pass then undefined is passed

function sayhello(params) {
  console.log("hello");
  return 1;
}

sayhello();
linebreak();

// 2 . function  are first class citizens, they are treated as variables, in this way
//    they are also termed as anonymous function .
let anonymous_function = function (params) {
  console.log(
    "this is called as ananymous function and during calling it is called using the var name "
  );
};

anonymous_function();

linebreak();

// 3. IIFE - immediately invoked function experssion -- ye function bante hi call ho jata hai

(function iife(params) {
  console.log("so this function is called  as soon as it is created");
})();

linebreak();

// 4. arrow function
let arrowfunc = (var1) => 2 * var1 * var1;
console.log(arrowfunc(3));

linebreak();

// 5 .passing function as parameter to the funtion  since the funtion can be stored in the variable
//   and after passing we can call them as well , inside the main function
function main(params) {
  console.log("i am in the main function ");
  console.log(params);
  params();
}
function topass(params) {
  console.log(
    " i am the function which has been passed and has been called in the main function "
  );
}

main(topass);

linebreak();

// 6 . returning function from function

function returner() {
  console.log(" i am inside the main function ");
  let inner = function (params) {
    console.log("the passed parameter is " + params);
    console.log(" I am the inner function ");
  };
  return inner;
}

returner();
let retfun = returner(); // see the returned function has been called , which we can assign in variable as well
console.log(retfun(44));

linebreak();

// 7. closure (*** to be discussed later ***)

linebreak();
