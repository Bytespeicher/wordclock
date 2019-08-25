import { h } from "preact";
import {Link} from 'preact-router'


const Page = () => {

  return (
    <div>
      <p>This is the Index Page</p>
      <Link href="/update">Updater</Link>
    </div>
  )
};

export default Page