function counter() {
  let count = 0;
  return {
    inc() { count++; },
    get() { return count; }
  };
}

const c = counter();
c.inc();
console.log(c.get()); // 1
c.inc();
c.inc();
console.log(c.get()); // 1


const multiply = a => b => a * b;

multiply(2)(5); // 10