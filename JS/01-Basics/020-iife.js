// IIFE - Immediately Invoked Function Expression
// IIFE is a function that is executed right after it is created.
// IIFE is a design pattern that is also known as a Self-Executing Anonymous Function and contains two major parts:
// The first is the anonymous function with lexical scope enclosed within the Grouping Operator ().
// This prevents accessing variables within the IIFE idiom as well as polluting the global scope.
// The second part creates the immediately invoked function expression () through which the JavaScript engine will directly interpret the function.
// IIFE is used to avoid variable hoisting from within the block scope.

// IIFE is used to globally expose a variable or function without polluting the global scope.

(function namedIIFE() {
    console.log('DB Connected')
})();

(() => {
    console.log('DB Connected Two')
})()