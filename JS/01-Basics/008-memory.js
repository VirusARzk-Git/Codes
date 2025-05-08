// Stack(Primitive) : LIFO
// Heap(Non-Primitive) : Random Memory Allocation

let myYoutubeName = "VirusARzk YT"
let anotherName = myYoutubeName

console.log(myYoutubeName, anotherName)

anotherName = "VirusARzk Shitt"

console.log(myYoutubeName, anotherName)
/*
Primitive Data Types are stored in Stack Memory

So, when we assign a primitive data type to another variable,
it creates a copy of the value in the new variable.

So, when we change the value of the new variable,
it does not affect the original variable.
*/


let user1 = {
    email: "xyz@xyz.com",
    upi: "xyz@upi"
}

let user2 = user1

console.log(user1, user2)

user2.email = "aditya@gmail.com"
user2.upi = "aditya@upi"

console.log(user1, user2)
/*
Non-Primitive Data Types are stored in Heap Memory

So, when we assign a non-primitive data type to another variable,
it does not create a copy of the value in the new variable.

Instead, it creates a reference to the original variable.

So, when we change the value of the new variable,
it also affects the original variable.
*/
