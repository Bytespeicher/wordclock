import { h, render } from "preact";
import { useState } from 'preact/hooks';

import Router, { Link } from 'preact-router';

import IndexPage from './pages/index';
import UpdatePage from './pages/update';

import Button from './components/button';
import { getMaxListeners } from "cluster";

const App = () => {
  const [ counter, setCounter ] = useState(0);
  return (
  <div>
    <header className="sticky">
      <a href="#" className="logo">Wordclock</a>
      <a href="#" className="button">Einstellungen</a>
      <a href="#" className="button">Update</a>
      <button>Download</button>
    </header>

    <Router>
      <IndexPage path="/" />
      <UpdatePage path="/update" />
    </Router>

    <footer className="sticky">
      <p>© 2019 Tillmann Hübner {<Link href="mailto:ruohki@gmail.com">{"ruohki@gmail.com"}</Link>}</p>
    </footer>
  </div>

  )
}


if (typeof window !== "undefined") {
  render(<App />, document.getElementById("root"));
}
