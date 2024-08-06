// Stack(Primitive) : LIFO
// Heap(Non-Primitive) : Random Memory Allocation

let myYoutubeName = "VirusARzk YT"
let anotherName = myYoutubeName

console.log(myYoutubeName, anotherName)

anotherName = "VirusARzk Shitt"

console.log(myYoutubeName, anotherName)

let user1 = {
    email : "xyz@xyz.com",
    upi : "xyz@upi"
}

let user2 = user1

console.log(user1, user2)

user2.email = "aditya@gmail.com"
user2.upi = "aditya@upi"

console.log(user1, user2)
