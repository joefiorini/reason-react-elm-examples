module UnorderedList = {
  include ReactRe.Component;
  let name = "UnorderedList";
  type props = unit;
  let text = ReactRe.stringToElement;
  let render _ =>
    <ul>
      <li> (text "Pamplemousse") </li>
      <li> (text "Ananas") </li>
      <li> (text "Jus d'orange") </li>
      <li> (text "Boeuf") </li>
      <li> (text "Soupe du jour") </li>
      <li> (text "Camembert") </li>
      <li> (text "Jacques Cousteau") </li>
      <li> (text "Baguette") </li>
    </ul>;
};

include ReactRe.CreateComponent UnorderedList;

let createElement = wrapProps ();
