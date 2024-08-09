const userEmail = 'aditya@gmail.com';

if (userEmail) {
    console.log('Email is valid');
}
else {
    console.log('Email is invalid');
}

// falsey values in JavaScript are:
// 0, -0, 0n, '', null, undefined, NaN, false

// All other values are truthy. In this case, since userEmail is a string, it is truthy.

// truthy values in JavaScript are:
// "0", " ", [], {}, function() {}, 'false', 'null', 'undefined', 'NaN'

const emptyObj = {};
if(Object.keys(emptyObj).length === 0) {
    console.log('Object is empty');
}

// Nullish Coalescing Operator (??) is used to check if a value is null or undefined.

let val1;
val1 = 5 ?? 10;
console.log(val1);

val1 = null ?? 15;
console.log(val1);

val1 = undefined ?? 20;
console.log(val1);
