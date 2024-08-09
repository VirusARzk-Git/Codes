// singleton

// object literals

const mySym = Symbol('key1')
const jsUser = {
    name: 'Aditya',
    "full name": 'Aditya Raj',
    age: 23,
    [mySym]: 'value',
    isAdmin: true,
    email: 'aditya@google.com',
}

console.log(jsUser)

console.log(jsUser.name)
console.log(jsUser['name'])
console.log(jsUser['full name'])    // use this when key has spaces
console.log(jsUser[mySym])
console.log(typeof jsUser[mySym])

jsUser.email = 'aditya@microsoft.com'
// Object.freeze(jsUser)
jsUser.email = 'aditya@yahoo.com'
console.log(jsUser)

jsUser.greeting = function() {
    console.log('Hello jsUser')
}

jsUser.greetingTwo = () => {
    console.log(`Hello jsUser, ${jsUser["full name"]}`)
}

console.log(jsUser.greeting)
console.log(jsUser.greetingTwo)
jsUser.greeting()
jsUser.greetingTwo()

console.log(Object.keys(jsUser));

delete jsUser.greeting
delete jsUser.greetingTwo
console.log(jsUser)