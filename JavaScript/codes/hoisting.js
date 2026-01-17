console.log("Age : " , age)

f1() // ✅ fully hoisted 
sayHi(); // ❌ TypeError

// let age = 20  // ❌ ReferenceError
var age = 20

function f1 (){
    console.log("Age2 : " , age)
}

var sayHi = function () {
  console.log("Hi");
};



console.log("Age2 : " , age)
