import { h  } from "preact";
import { useState } from 'preact/hooks';
import {Link} from 'preact-router'
import axios from 'axios';


const Page = () => {
  const [ biosFile, setBiosFile ] = useState();
  const [ percent, setPercent ] = useState(0);
  const [ uploading, setUploading ] = useState(false);

  console.log(biosFile)

  const uploadFile = () => {
    setUploading(true);

    const formData = new FormData()
    formData.append('file', biosFile)

    axios.request({
      method: "post", 
      url: "http://192.168.178.56/update", 
      data: formData, 
      onUploadProgress: (p) => {
        setPercent(p.loaded / p.total);
      }
    }).then (data => {
      setPercent(1.0);
      setUploading(false);
    }).catch(err => {
      setPercent(1.0);
      setUploading(false);
      console.log(err)
    })
  }

  return ( 
    <div>
      <p>This is the Update Page</p>
      <Link href="/">Index</Link>
      <hr />
      {!uploading ? (
        <div>
          <input onChange={({ target }) => setBiosFile(target.files[0])} type="file">Firmware: </input>
          <button onClick={uploadFile}>Upload</button>
        </div>
      ):(
        <p>Fortschritt: {Math.round(percent * 100)}%</p>
      )}
    </div>
  )
};

export default Page