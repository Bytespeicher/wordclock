import { h } from "preact";

import './style.scss';

const Button = ({ children, ...rest }) => {
  return (
    <button {...rest} class="button">{children}</button>
  );
}

export default Button;