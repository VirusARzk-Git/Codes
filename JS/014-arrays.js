const marvel_heros = ['Hulk','Iron Man']
const dc_heros = ['Batman','Superman']

// marvel_heros.push(dc_heros)
// console.log(marvel_heros)

// marvel_heros.push(...dc_heros)
// console.log(marvel_heros)

const allHeroes = marvel_heros.concat(dc_heros)
console.log(allHeroes)

const all_heroes = [...marvel_heros, ...dc_heros]
console.log(all_heroes)

const arr = [1,2,3,[4,5],6,[7,[8,9]]]
console.log(arr.flat(Infinity))

console.log(Array.from('hello'))
console.log(Array.from({length: 5}, (v, i) => i))
console.log(Array.from({name: 'John'})) // []

let score1 = 100, score2 = 200, score3 = 300
console.log(Array.of(score1, score2, score3))

