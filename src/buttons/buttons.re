module Buttons = {
  include ReactRe.Component.Stateful;
  let name = "Buttons";
  type props = unit;
  type action =
    | Increment
    | Decrement;
  let text = ReactRe.stringToElement;
  type state = {count: int};
  let getInitialState _ => {count: 0};
  let makeHandler action {state} _ =>
    switch action {
    | Increment => Some {count: state.count + 1}
    | Decrement => Some {count: state.count - 1}
    };
  let render {updater, state} =>
    <div>
      <button onClick=(updater (makeHandler Decrement))> (text "-") </button>
      <div> (text (string_of_int state.count)) </div>
      <button onClick=(updater (makeHandler Increment))> (text "+") </button>
    </div>;
};

include ReactRe.CreateComponent Buttons;

let createElement = wrapProps ();
