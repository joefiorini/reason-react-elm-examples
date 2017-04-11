type model = {name: string, password: string, passwordAgain: string};

module Validation = {
  module VComp = {
    include ReactRe.Component;
    let name = "Validation";
    type props = model;
    let getStatus status =>
      if status {
        ("green", "OK")
      } else {
        ("red", "Passwords do not match!")
      };
    let render {props} => {
      let (color, message) = getStatus (props.password == props.passwordAgain);
      let myStyle = ReactDOMRe.Style.make ::color ();
      <div style=myStyle> (ReactRe.stringToElement message) </div>
    };
  };
  include ReactRe.CreateComponent VComp;
  let createElement ::model => wrapProps model;
};

module Form = {
  include ReactRe.Component.Stateful;
  let name = "Form";
  type props = unit;
  let text = ReactRe.stringToElement;
  type state = model;
  type action =
    | Name
    | Password
    | PasswordAgain;
  let getInitialState _ => {name: "", password: "", passwordAgain: ""};
  let makeHandler field {state} event => {
    let value = (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value;
    switch field {
    | Name => Some {...state, name: value}
    | Password => Some {...state, password: value}
    | PasswordAgain => Some {...state, passwordAgain: value}
    }
  };
  let reverse str => {
    let arr2 = Js_array.reverseInPlace (Js_string.split "" str);
    Js_array.joinWith "" arr2
  };
  let myStyle =
    ReactDOMRe.Style.make
      width::"100%" height::"40px" padding::"10px 0" fontSize::"2em" textAlign::"center" ();
  let render {updater, state} =>
    <div>
      <input _type="text" placeholder="Name" onChange=(updater (makeHandler Name)) />
      <input _type="password" placeholder="Password" onChange=(updater (makeHandler Password)) />
      <input
        _type="password"
        placeholder="Re-enter Password"
        onChange=(updater (makeHandler PasswordAgain))
      />
      <Validation model=state />
    </div>;
};

include ReactRe.CreateComponent Form;

let createElement = wrapProps ();
