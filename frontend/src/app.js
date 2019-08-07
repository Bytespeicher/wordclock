import { h, render } from "preact";
import { useState } from 'preact/hooks';

import Button from './components/button';

const App = () => {
  const [ counter, setCounter ] = useState(0);

  return (
    <div>
      <Button onClick={() => setCounter(counter + 1)}>Clicky ({counter})</Button>
      <button onClick={() => {
        fetch("/restart");
      }}></button>
    </div>
  )
}


if (typeof window !== "undefined") {
  render(<App />, document.getElementById("root"));
}
