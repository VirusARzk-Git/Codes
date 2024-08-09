let val1 = "25"
let val2 = "25a"
let val3 = null
let val4 = undefined

let value1InNumber = Number(val1)
let value2InNumber = Number(val2)
let value3InNumber = Number(val3)
let value4InNumber = Number(val4)

console.table({value1InNumber, value2InNumber, value3InNumber, value4InNumber})