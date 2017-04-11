module Field = {
  include ReactRe.Component.Stateful;
  let name = "Field";
  type props = unit;
  let text = ReactRe.stringToElement;
  type state = {message: string};
  let getInitialState _ => {message: ""};
  let handleChange _ event => {
    let value = (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value;
    Some {message: value}
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
      <input placeholder="Text to reverse" onChange=(updater handleChange) style=myStyle />
      <div style=myStyle> (text (reverse state.message)) </div>
    </div>;
};

include ReactRe.CreateComponent Field;

let createElement = wrapProps ();
