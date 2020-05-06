const Napi1 = require("../lib/binding.js");
const assert = require("assert");

assert(Napi1, "The expected function is undefined");

function testBasic()
{
    const result =  Napi1("hello");
    assert.strictEqual(result, "world", "Unexpected value returned");
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

console.log("Tests passed- everything looks OK!");